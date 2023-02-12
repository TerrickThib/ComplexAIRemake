// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include <Components/BoxComponent.h>

// Sets default values
AProjectile::AProjectile()
{
	InitialLifeSpan = 3.0f;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Bullet"));
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	UStaticMesh* Asset = MeshAsset.Object;

	//Sets Collision box
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	
	//Mesh
	mesh->SetSimulatePhysics(true);
	mesh->SetStaticMesh(Asset);
	mesh->SetRelativeScale3D({ 4.0f, 0.5f, 0.5f });
	
	//Ignores Collision with pawn
	CollisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

	//Moves Collision box and mesh
	movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Bullet Movement"));
	movement->UpdatedComponent = CollisionBox;
	movement->UpdatedComponent = mesh;
	movement->InitialSpeed = 3000.0f;
	movement->MaxSpeed = 3000.0f;
	movement->bRotationFollowsVelocity = true;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}




