#pragma once
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};
enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

const std::vector<CardKind> kind_of_card {
    CardKind::Heart,
    CardKind::Diamond,
    CardKind::Club,
    CardKind::Spade
};
const std::vector<CardValue> value_of_card {
    CardValue::Two,
    CardValue::Three,
    CardValue::Four,
    CardValue::Five,
    CardValue::Six,
    CardValue::Seven,
    CardValue::Eight,
    CardValue::Nine,
    CardValue::Ten,
    CardValue::Jack,
    CardValue::Queen,
    CardValue::King,
    CardValue::Ace,
};

const std::unordered_map<CardKind, std::string> kind_to_string = {
    {CardKind::Heart, "Heart"},
    {CardKind::Diamond, "Diamond"},
    {CardKind::Club, "Club"},
    {CardKind::Spade, "Spade"}
};
const std::unordered_map<CardValue, std::string> value_to_string = {
    {CardValue::Two, "Two"},
    {CardValue::Three, "Three"},
    {CardValue::Four, "Four"},
    {CardValue::Five, "Five"},
    {CardValue::Six, "Six"},
    {CardValue::Seven, "Seven"},
    {CardValue::Eight, "Eight"},
    {CardValue::Nine, "Nine"},
    {CardValue::Ten, "Ten"},
    {CardValue::Jack, "Jack"},
    {CardValue::Queen, "Queen"},
    {CardValue::King, "King"},
    {CardValue::Ace, "Ace"}
};

struct Card {
    CardKind kind;
    CardValue value;

    size_t hash()const;
};

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size);
bool operator==(Card A, Card B);
size_t hash_perso (Card card);

std::vector<size_t> hash_paquet (std::vector<Card> paquet);
//bool verif_repeat(std::vector<size_t> vec);
void display_verif_paquet (std::vector<Card> paquet);
std::vector<Card> paquet();

std::unordered_map<Card, int> table_de_comptage (std::vector<Card> const& cartes);
std::string card_name(Card const& card);
void display_comptage(std::unordered_map<Card, int> cartes_comptees);