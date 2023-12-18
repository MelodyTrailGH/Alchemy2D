#pragma once

namespace Alchemy2D::Utility::Math {
	class Vector2 {
	  private:
		float x;
		float y;

	  public:
		Vector2( ) = default;
		~Vector2( ) = default;
		explicit Vector2( float position );
		Vector2( float xPosition, float yPosition );

		Vector2( const Vector2& other ) = default;     // Copy Con
		Vector2( Vector2&& other ) noexcept = default; // Move Con

		Vector2& operator=( const Vector2& other );
		Vector2& operator=( Vector2&& other ) noexcept;
		Vector2 operator+( const Vector2& other ) const;
		Vector2 operator+( float value ) const;
		Vector2 operator-( const Vector2& other ) const;
		Vector2 operator-( float value ) const;
		Vector2 operator/( const Vector2& other ) const;
		Vector2 operator/( float value ) const;
		Vector2 operator*( const Vector2& other ) const;
		Vector2 operator*( float value ) const;

		void operator+=( const Vector2& other );
		void operator+=( float value );
		void operator-=( const Vector2& other );
		void operator-=( float value );
		void operator*=( const Vector2& other );
		void operator*=( float value );
		void operator/=( const Vector2& other );
		void operator/=( float value );

		bool operator==( const Vector2& other ) const;
		bool operator==( float value ) const;
		bool operator>=( const Vector2& other ) const;
		bool operator>=( float value ) const;

		[[nodiscard]] float getX( ) const;
		[[nodiscard]] float getY( ) const;
		void setX( float value );
		void setY( float value );

		/**
		 * @brief Gets the length of the vector.
		 *
		 * @return float
		 */
		float length( );

		/**
		 * @brief Gets the squared length of the vector.
		 *
		 * @return float
		 */
		float lengthSquared( );

		/**
		 * @brief Gets the dot product of this vector and another.
		 *
		 * @param other The other vector.
		 * @return float
		 */
		float dotProduct( Vector2 other );

		/**
		 * @brief Gets the distance from this vector to another.
		 *
		 * @param other The endpoint vector.
		 * @return float
		 */
		float distance( Vector2 other );

		/**
		 * @brief Gets the distance (squared) from this vector to another.
		 *
		 * @param other The endpoint vector.
		 * @return float
		 */
		float distanceSquared( Vector2 other );

		/**
		 * @brief Gets the angle between this vector and another.
		 *
		 * @param other The other vector.
		 * @return float
		 */
		float angleBetween( Vector2 other );
	};
} // namespace Alchemy2D::Utility::Math