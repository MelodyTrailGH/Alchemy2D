#include "Alchemy2D/Core/Math/Vector2.hh"
#include <utility>

namespace Alchemy2D::Utility::Math {
	Vector2::Vector2( float position ) : x( position ), y( position ) {
	}

	Vector2::Vector2( float xPosition, float yPosition ) : x( xPosition ), y( yPosition ) {
	}

	Vector2& Vector2::operator=( const Vector2& other ) {
		return *this = Vector2( other );
	}

	Vector2& Vector2::operator=( Vector2&& other ) noexcept {
		std::swap( this->x, other.x );
		std::swap( this->y, other.y );
		return *this;
	}

	Vector2 Vector2::operator+( const Vector2& other ) const {
		return { this->x + other.x, this->y + other.y };
	}

	Vector2 Vector2::operator+( float value ) const {
		return { this->x + value, this->y + value };
	}

	Vector2 Vector2::operator-( const Vector2& other ) const {
		return { this->x - other.x, this->y - other.y };
	}

	Vector2 Vector2::operator-( float value ) const {
		return { this->x - value, this->y - value };
	}

	Vector2 Vector2::operator/( const Vector2& other ) const {
		return { this->x / other.x, this->y / other.y };
	}

	Vector2 Vector2::operator/( float value ) const {
		return { this->x / value, this->y / value };
	}

	Vector2 Vector2::operator*( const Vector2& other ) const {
		return { this->x * other.x, this->y * other.y };
	}

	Vector2 Vector2::operator*( float value ) const {
		return { this->x * value, this->y * value };
	}

	void Vector2::operator+=( const Vector2& other ) {
		this->x += other.x;
		this->y += other.y;
	}

	void Vector2::operator+=( float value ) {
		this->x += value;
		this->y += value;
	}

	void Vector2::operator-=( const Vector2& other ) {
		this->x -= other.x;
		this->y -= other.y;
	}

	void Vector2::operator-=( float value ) {
		this->x -= value;
		this->y -= value;
	}

	void Vector2::operator*=( const Vector2& other ) {
		this->x *= other.x;
		this->y *= other.y;
	}

	void Vector2::operator*=( float value ) {
		this->x *= value;
		this->y *= value;
	}

	void Vector2::operator/=( const Vector2& other ) {
		this->x /= other.x;
		this->y /= other.y;
	}

	void Vector2::operator/=( float value ) {
		this->x /= value;
		this->y /= value;
	}

	bool Vector2::operator==( const Vector2& other ) const {
		return ( this->x == other.x && this->y == other.y );
	}
	bool Vector2::operator==( float value ) const {
		return ( this->x == value && this->y == value );
	}

	float Vector2::getX( ) const {
		return this->x;
	}

	float Vector2::getY( ) const {
		return this->y;
	}
	void Vector2::setX( float value ) {
		this->x = value;
	}
	void Vector2::setY( float value ) {
		this->y = value;
	}
} // namespace Alchemy2D::Utility::Math