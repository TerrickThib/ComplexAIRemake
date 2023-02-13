// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include "Projectile.generated.h"

UCLASS()
class COMPLEXAIREMAKE_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	AActor* target;
	UStaticMeshComponent* mesh;

	//Addes Box Collsion 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UBoxComponent* CollisionBox;

	UProjectileMovementComponent* movement;
	float getSpeed() { return m_speed; }
	void setSped(float speed) { m_speed = speed; }
	FVector getMoveDirection() { return m_moveDirection; }
	void setMoveDirection(FVector direction) { m_moveDirection = direction; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	float m_speed = 20000.0f;
	FVector m_moveDirection;
	FVector m_velocity;
};
