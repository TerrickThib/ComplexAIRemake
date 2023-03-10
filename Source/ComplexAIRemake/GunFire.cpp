// Fill out your copyright notice in the Description page of Project Settings.


#include "GunFire.h"
#include "NPC_AIController.h"
#include "NPC.h"
#include "ComplexAIRemakeCharacter.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Runtime/Engine/Classes/Engine/World.h>
#include <Engine/LatentActionManager.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include <GameFramework/Character.h>	
#include "Components/SkeletalMeshComponent.h"
#include "Projectile.h"



UGunFire::UGunFire(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Gun Fire");
}

EBTNodeResult::Type UGunFire::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	//Gets the NPC
	AAIController* const cont = owner_comp.GetAIOwner();
	ANPC* const npc = Cast<ANPC>(cont->GetPawn());
	
	APlayerController* const playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AComplexAIRemakeCharacter* const player = Cast<AComplexAIRemakeCharacter>(playerController->GetPawn());

	//Makes it so projectile can be spawned
	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>();
	projectile->setMoveDirection(npc->GetActorForwardVector());
	projectile->SetActorLocation(npc->GetActorLocation());
	
	

	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

