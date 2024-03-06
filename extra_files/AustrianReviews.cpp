#include "AustrianReviews.h"


AustrianReview::AustrianReview (std::string _datePublished,
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
                        int _verified)
: datePublished(_datePublished),
  rating(_rating),
  maxRating(_maxRating),
  title(_title),
  author(_author),
  country(_country),
  date(_date),
  reviewBody(_reviewBody),
  travelType(_travelType),
  seatType(_seatType),
  recommended(_recommended),
  aircraft(_aircraft),
  verified(_verified)
{
    
}