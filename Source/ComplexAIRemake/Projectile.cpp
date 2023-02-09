// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Bullet"));
	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	UStaticMesh* Asset = MeshAsset.Object;

	mesh->SetStaticMesh(Asset);
	mesh->SetRelativeScale3D({ 4.0f, 0.5f, 0.5f });

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}



