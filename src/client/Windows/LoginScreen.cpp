/*
** EPITECH PROJECT, 2021
** B-CPP-500-REN-5-1-babel-aurelien.joncour
** File description:
** LoginScreen
*/

#include "LoginScreen.hpp"
#include <QFont>

LoginScreen::LoginScreen(QWidget *parent) : QWidget(parent),
                                            _welcomeText(std::make_unique<QLabel>(this)),
                                            _errorLabel(std::make_unique<QLabel>(this)),
                                            _usernameField(std::make_unique<QLineEdit>(this)),
                                            _loginButton(std::make_unique<QPushButton>(this)),
                                            _layout(std::make_unique<QVBoxLayout>())
{
    this->setStyleSheet("background-color:#8789E8;color:#0E312C;");

    _welcomeText->setText("Welcome on Babel VOIP Application!");
    _welcomeText->setAlignment(Qt::AlignCenter);
    _welcomeText->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    _welcomeText->setFont(QFont("Arial", 24, QFont::Bold));

    _errorLabel->setAlignment(Qt::AlignCenter);
    _errorLabel->setFont(QFont("Arial", 16, QFont::Bold));
    _errorLabel->setStyleSheet("QLabel {color : red; }");

    _usernameField->move(100, 200);
    _usernameField->setPlaceholderText("Username");

    _loginButton->setText("login");

    _layout->addWidget(_welcomeText.get(), Qt::AlignCenter);
    _layout->addWidget(_errorLabel.get(), Qt::AlignCenter);
    _layout->addWidget(_usernameField.get(), Qt::AlignCenter);
    _layout->addWidget(_loginButton.get(), Qt::AlignCenter);

    setLayout(_layout.get());
}

LoginScreen::~LoginScreen()
{
}

QPushButton *LoginScreen::getLoginButton() const noexcept
{
    return _loginButton.get();
}

QLineEdit *LoginScreen::getUsernameField() const noexcept
{
    return _usernameField.get();
}

void LoginScreen::showBadCharError() const noexcept
{
    _errorLabel->setText("Only alphanumeric character and dash are allowed");
}

void LoginScreen::showMissingCharError() const noexcept
{
    _errorLabel->setText("You need to have at least one alphabetical character");
}

void LoginScreen::showEmptyUsernameError() const noexcept
{
    _errorLabel->setText("Please enter a username with at least one alphabetical character");
}
