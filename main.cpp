#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
class HangmanDrawer {
public:
    HangmanDrawer(sf::RenderWindow& window) : window(window) {
        if (!font.loadFromFile("arial.ttf")) {
            throw runtime_error("Error loading font");
        }
        text.setFont(font);
        text.setCharacterSize(18);
        text.setFillColor(sf::Color::Green);
        text.setPosition(40, 40);
    }

    void updateText(const std::string& newText) {
        text.setString(newText);
    }

    void drawHangman(int incorrectGuesses) {
        
        sf::Vector2u windowSize = window.getSize();
        float centerX = windowSize.x / 2.0f;
        float centerY = windowSize.y / 2.0f;

        
        drawGallows(centerX, centerY);

        
        drawHead(centerX, centerY, incorrectGuesses);
        drawBody(centerX, centerY, incorrectGuesses);
        drawArms(centerX, centerY, incorrectGuesses);
        drawLegs(centerX, centerY, incorrectGuesses);
    }

    void displayGame(const std::string& guessed, const std::vector<char>& incorrectGuesses, int attempts, const std::string& currentPlayer, const std::string& word) {
        std::stringstream ss;
        ss << "WORD: " << guessed << "\n";
        ss << "INCORRECT GUESSES: ";
        for (char ch : incorrectGuesses) {
            ss << ch << ' ';
        }
        ss << "\nAttempts left: " << attempts << "\n";
        ss << currentPlayer << "'s Turn\n";
        updateText(ss.str());

        window.clear(sf::Color::Black);
        drawHangman(6 - attempts); 
        window.draw(text);

        if (attempts == 0 || guessed == word) {
            std::string gameOverText = guessed == word ? "Congratulations! You've guessed the word!" : "Game Over! The word was " + word;
            sf::Text gameOver(gameOverText, font, 30);
            gameOver.setFillColor(sf::Color::Red);
            gameOver.setPosition(40, window.getSize().y / 2.0f - 20); 
            window.draw(gameOver);
        }

        window.display();
    }



private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text text;

    void drawGallows(float centerX, float centerY) {
        
        sf::VertexArray gallowsBase(sf::LinesStrip, 2);
        gallowsBase[0].position = sf::Vector2f(centerX - 25, centerY + 100);
        gallowsBase[1].position = sf::Vector2f(centerX + 25, centerY + 100);
        gallowsBase[0].color = sf::Color::White;
        gallowsBase[1].color = sf::Color::White;
        window.draw(gallowsBase);

        sf::VertexArray gallowsPole(sf::LinesStrip, 2);
        gallowsPole[0].position = sf::Vector2f(centerX, centerY + 100);
        gallowsPole[1].position = sf::Vector2f(centerX, centerY - 100);
        gallowsPole[0].color = sf::Color::White;
        gallowsPole[1].color = sf::Color::White;
        window.draw(gallowsPole);

        sf::VertexArray gallowsTop(sf::LinesStrip, 2);
        gallowsTop[0].position = sf::Vector2f(centerX, centerY - 100);
        gallowsTop[1].position = sf::Vector2f(centerX + 50, centerY - 100);
        gallowsTop[0].color = sf::Color::White;
        gallowsTop[1].color = sf::Color::White;
        window.draw(gallowsTop);

        sf::VertexArray gallowsRope(sf::LinesStrip, 2);
        gallowsRope[0].position = sf::Vector2f(centerX + 50, centerY - 100);
        gallowsRope[1].position = sf::Vector2f(centerX + 50, centerY - 50);
        gallowsRope[0].color = sf::Color::White;
        gallowsRope[1].color = sf::Color::White;
        window.draw(gallowsRope);
    }

    void drawHead(float centerX, float centerY, int incorrectGuesses) {
        if (incorrectGuesses > 0) {
            sf::CircleShape head(15);
            head.setFillColor(sf::Color::White);
            head.setOutlineThickness(2);
            head.setOutlineColor(sf::Color::White);
            head.setPosition(centerX + 35, centerY - 90);
            window.draw(head);
        }
    }

    void drawBody(float centerX, float centerY, int incorrectGuesses) {
        if (incorrectGuesses > 1) {
            sf::VertexArray body(sf::LinesStrip, 2);
            body[0].position = sf::Vector2f(centerX + 50, centerY - 75);
            body[1].position = sf::Vector2f(centerX + 50, centerY - 35);
            body[0].color = sf::Color::White;
            body[1].color = sf::Color::White;
            window.draw(body);
        }
    }

    void drawArms(float centerX, float centerY, int incorrectGuesses) {
        if (incorrectGuesses > 2) {
            sf::VertexArray leftArm(sf::LinesStrip, 2);
            leftArm[0].position = sf::Vector2f(centerX + 50, centerY - 70);
            leftArm[1].position = sf::Vector2f(centerX + 20, centerY - 70);
            leftArm[0].color = sf::Color::White;
            leftArm[1].color = sf::Color::White;
            window.draw(leftArm);
        }

        if (incorrectGuesses > 3) {
            sf::VertexArray rightArm(sf::LinesStrip, 2);
            rightArm[0].position = sf::Vector2f(centerX + 50, centerY - 70);
            rightArm[1].position = sf::Vector2f(centerX + 80, centerY - 70);
            rightArm[0].color = sf::Color::White;
            rightArm[1].color = sf::Color::White;
            window.draw(rightArm);
        }
    }

    void drawLegs(float centerX, float centerY, int incorrectGuesses) {
        if (incorrectGuesses > 4) {
            sf::VertexArray leftLeg(sf::LinesStrip, 2);
            leftLeg[0].position = sf::Vector2f(centerX + 50, centerY - 35);
            leftLeg[1].position = sf::Vector2f(centerX + 20, centerY + 20);
            leftLeg[0].color = sf::Color::White;
            leftLeg[1].color = sf::Color::White;
            window.draw(leftLeg);
        }

        if (incorrectGuesses > 5) {
            sf::VertexArray rightLeg(sf::LinesStrip, 2);
            rightLeg[0].position = sf::Vector2f(centerX + 50, centerY - 35);
            rightLeg[1].position = sf::Vector2f(centerX + 80, centerY + 20);
            rightLeg[0].color = sf::Color::White;
            rightLeg[1].color = sf::Color::White;
            window.draw(rightLeg);
        }
    }
};


class Player {
public:
    Player(const std::string& name) : name(name), score(0) {}

    void increaseScore() {
        ++score;
    }

    int getScore() const {
        return score;
    }

    const std::string& getName() const {
        return name;
    }

private:
    std::string name;
    int score;
};

class HangmanGame {
public:
    HangmanGame(sf::RenderWindow& window, HangmanDrawer& drawer)
        : window(window), drawer(drawer), roundNumber(1) {
        players.push_back(Player("Player 1"));
        players.push_back(Player("Player 2"));
    }

    void playRound() {
        std::string word;
        Player& currentPlayer = players[roundNumber % 2];
        Player& guessingPlayer = players[(roundNumber + 1) % 2];

        std::cout << "| R O U N D " << roundNumber << ": |\n";
        std::cout << endl;
        
        std::cout << currentPlayer.getName() << "|ENTER A WORD: ";
        std::cin >> word;
        std::cin.ignore(); 

        system("cls");


        std::cout << "|GUESS THE WORD|\n";
        std::cout << std::endl;

        
        std::string guessed(word.size(), '_'); 
        std::vector<char> incorrectGuesses;
        int attempts = 6;

        
        while (attempts > 0 && guessed != word) {
            drawer.displayGame(guessed, incorrectGuesses, attempts, guessingPlayer.getName(), word);


            bool validInput = false;
            while (window.isOpen() && !validInput) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                    else if (event.type == sf::Event::TextEntered) {
                        if (event.text.unicode < 128) {
                            char guess = tolower(static_cast<char>(event.text.unicode));
                            if (guess >= 'a' && guess <= 'z') {
                                if (word.find(guess) != std::string::npos) {
                                   
                                    for (size_t i = 0; i < word.size(); ++i) {
                                        if (word[i] == guess) {
                                            guessed[i] = guess;
                                        }
                                    }
                                }
                                else {
                                    
                                    if (find(incorrectGuesses.begin(), incorrectGuesses.end(), guess) == incorrectGuesses.end()) {
                                        incorrectGuesses.push_back(guess);
                                        --attempts;
                                    }
                                }
                                validInput = true;
                            }
                        }
                        if (event.text.unicode == '\r') { 
                            validInput = true;
                        }
                    }
                }
            }
        }

        if (guessed == word) {
            cout << "|C O N G R A T U L A T I O N S|/n " << guessingPlayer.getName() << "! You've guessed the word!\n";
            guessingPlayer.increaseScore();
        }
        else {
            cout << "|S O R R Y| \n " << guessingPlayer.getName() << ". You've run out of attempts. The word was |" << word << "|.\n" << endl;
        }

        roundNumber++;
    }

    void startGame() {
        while (window.isOpen()) {
            playRound();

           
            cout << "|Player 1 Score: " << players[0].getScore() << "|\n";
            cout << "|Player 2 Score: " << players[1].getScore() << "|\n" << endl;
            cout << "Press enter";
            cin.ignore(); 
        }
    }

private:
    sf::RenderWindow& window;
    HangmanDrawer& drawer;
    vector<Player> players;
    int roundNumber;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "Hangman Game");

    try {
        HangmanDrawer drawer(window);
        HangmanGame game(window, drawer);
        game.startGame();
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
