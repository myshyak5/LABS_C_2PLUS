#include <SFML/Graphics.hpp>
#include "main.hpp"
#include <iostream>
#include <vector>
using namespace sf;

class Block {
    public:
        RectangleShape shape;
        bool isActive;
        Block(float width, float high) : isActive(true) {
            shape.setSize({width, high});
            shape.setFillColor(Color::Blue);
        }
        void draw(RenderWindow& window) {
            if (isActive) {
                window.draw(shape);
            }
        }
        bool checkCollision(const CircleShape& ball) {
            if (isActive && shape.getGlobalBounds().findIntersection(ball.getGlobalBounds())) {
                isActive = false;
                return true;
            }
            return false;
        }
    };
std::vector<Block> createBlocks(float circleRadius, int blockCount, int gap, float value_Y) {
    std::vector<Block> blocks;
    float start_X = (WINDOW_WIDTH - (blockCount * circleRadius * 2 + (blockCount - 1) * gap)) / 2;
    for (int i = 0; i < blockCount; i++) {
        Block block({circleRadius * 2, circleRadius});
        block.shape.setOrigin(block.shape.getSize() / 2.f);
        block.shape.setPosition({start_X + (circleRadius * 2 + gap) * i, WINDOW_HEIGHT * 0.1f + block.shape.getSize().y * value_Y + (value_Y != 0 ? gap * value_Y: 0)});
        blocks.push_back(block);
    }
    return blocks;
}
int main() {
    auto window = RenderWindow(VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), L"Моя игра");
    window.setFramerateLimit(40);

    unsigned int count = 0;
    Font font("C:\\Git\\LABS_C_2PLUS\\LAB_19_V7\\fonts\\arial.ttf");
    Text blocksBreak(font);
    blocksBreak.setCharacterSize(50);
    blocksBreak.setFillColor(Color::Cyan);
    blocksBreak.setPosition({25.f, 25.f});
    blocksBreak.setString(std::to_string(count));

    RectangleShape platform({WINDOW_WIDTH / 10.f, WINDOW_HEIGHT / 20.f});
    platform.setFillColor(Color::Red);
    platform.setOrigin(platform.getSize() / 2.f);
    platform.setPosition({WINDOW_WIDTH / 2.f, window.getSize().y * 0.85f});

    CircleShape ball(platform.getSize().x / 6);
    ball.setFillColor(Color::Green);
    ball.setOrigin({ball.getRadius(), ball.getRadius()});
    ball.setPosition({platform.getPosition().x, platform.getPosition().y - (platform.getSize().y / 2.f + ball.getRadius())});
    Vector2f velocity(WINDOW_WIDTH / 6.f, WINDOW_WIDTH / 6.f);
    
    std::vector<Block> blocks;
    float AllBlocks = 0;
    for (unsigned short i = 0; i < 6; i++) {
        float gap = ball.getRadius();
        unsigned int size = WINDOW_WIDTH - ball.getRadius() * 2;
        unsigned int blockCount = 1;
        while (size > gap) {
            size -= gap;
            if (size > ball.getRadius() * 2) {
                size -= ball.getRadius() * 2;
                blockCount++;
            }
        }
        if (i % 2 != 0) {
            blockCount -= 2;
        }
        blockCount -= i;
        AllBlocks += blockCount;
        std::vector<Block> newBlocks = createBlocks(ball.getRadius(), blockCount, gap, i);
        blocks.insert(blocks.end(), newBlocks.begin(), newBlocks.end());
    }

    Clock clock;
    float platformMove = 1;
    float FirstDeltaTime = clock.restart().asSeconds();
    float deltaTime = FirstDeltaTime;
    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<Event::Closed>()){
                window.close();
            }
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scan::Left && (platform.getPosition().x > platform.getSize().x / 2)) {
                    platform.move({-(platform.getSize().x / 10) * platformMove, 0});
                }
                if (keyPressed->scancode == sf::Keyboard::Scan::Right && (platform.getPosition().x < WINDOW_WIDTH - platform.getSize().x / 2)) {
                    platform.move({platform.getSize().x / 10 * platformMove, 0});
                }
            }
        }

        ball.move(velocity * deltaTime * 10000.f);

        if (ball.getPosition().x - ball.getRadius() < 0 || ball.getPosition().x + ball.getRadius() > WINDOW_WIDTH) {
            velocity.x = -velocity.x;
        }
        if (ball.getPosition().y - ball.getRadius() < 0) {
            velocity.y = -velocity.y;
        }
        if (ball.getGlobalBounds().findIntersection(platform.getGlobalBounds())) {
            if (velocity.y > 0) {
                velocity.y = -velocity.y;
                ball.setPosition({ball.getPosition().x, platform.getPosition().y - (platform.getSize().y / 2.f + ball.getRadius())});
            }
        }
        if (ball.getPosition().y + ball.getRadius() > WINDOW_HEIGHT) {
            ball.setPosition({platform.getPosition().x, platform.getPosition().y - (platform.getSize().y / 2.f + ball.getRadius())});
            count = 0;
            blocksBreak.setString(std::to_string(count));
            deltaTime = FirstDeltaTime;
            for (Block& block : blocks) {
                if (!block.isActive) {
                    block.isActive = true;
                }
            }
        }
        for (Block& block : blocks) {
            if (block.checkCollision(ball)) {
                AllBlocks--;
                velocity.y = -velocity.y;
                count++;
                blocksBreak.setString(std::to_string(count));
                deltaTime *= (1 + 1 / AllBlocks);
                platformMove *= (1 + 1 / AllBlocks);
                break;
            }
        }

        window.clear();
        window.draw(platform);
        window.draw(ball);
        for (Block& block : blocks) {
            block.draw(window);
        }
        window.draw(blocksBreak);
        window.display();
    }
    return 0;
}
