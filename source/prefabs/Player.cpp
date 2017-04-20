#include "Player.hpp"

namespace pg
{
	void Player::SetUpComponents()
	{
		auto playerController = this->AddComponent<PlayerControllerComponent>();
		auto position = this->AddComponent<PositionComponent>();
		auto velocity = this->AddComponent<VelocityComponent>();

		playerController->left = movementKey_t( sf::Keyboard::A, { -10.0f, 0.0f } );
		playerController->right = movementKey_t( sf::Keyboard::D, { 10.0f, 0.0f } );
		playerController->jump = movementKey_t( sf::Keyboard::Space, { 25.0f, 0.0f } );

		*position = sf::Vector2f( 0.0f, 0.0f );
		*velocity = sf::Vector2f( 0.0f, 0.0f );
	}

	void Player::Update()
	{
		auto playerController = this->GetComponent<PlayerControllerComponent>();
		auto position = this->GetComponent<PositionComponent>();
		auto velocity = this->GetComponent<VelocityComponent>();
		auto drawable = this->GetComponent<DrawableComponent>();

		if ( sf::Keyboard::isKeyPressed( playerController->left.key ) )
			playerController->pendingForce = playerController->left.force;
		if ( sf::Keyboard::isKeyPressed( playerController->right.key ) )
			playerController->pendingForce = playerController->right.force;
		if ( sf::Keyboard::isKeyPressed( playerController->jump.key ) && !playerController->lockJump )
		{
			playerController->pendingForce = playerController->jump.force;
			playerController->lockJump = false;
		}

		velocity->pendingForce += playerController->pendingForce;

		if ( drawable )
			drawable->sprites[0].setPosition( *position );
	}
}