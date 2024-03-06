#pragma once

#include <string>

enum class SeatType {economy, business, premium};
enum class TravelType {familyLeisure, soloLeisure, coupleLeisure, business};
enum class Recommended {no, NA};
enum class Verified {1, 0};

class AustrianReview 
{
    public:
        AustrianReview (std::string _datePublished,
                        int _rating,
                        int _maxRating,
                        std::string _title,
                        std::string _author,
                        std::string _country,
                        std::string _date,
                        std::string _reviewBody,
                        TravelType _travelType,
                        SeatType _seatType,
                        Recommended _recommended,
                        std::string _aircraft,
                        Verified _verified);

        std::string datePublished;
        int rating;
        int maxRating;
        std::string title;
        std::string author;
        std::string country;
        std::string date;
        std::string reviewBody;
        TravelType travelType;
        SeatType seatType;
        Recommended recommended;
        std::string aircraft;
        Verified verified;

};