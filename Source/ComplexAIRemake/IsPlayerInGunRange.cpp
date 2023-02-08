// Fill out your copyright notice in the Description page of Project Settings.


#include "IsPlayerInGunRange.h"
#include "NPC_AIController.h"
#include "NPC.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include <GameFramework/Character.h>
#include <Runtime/Engine/Classes/Engine/World.h>	
#include <BehaviorTree/BlackboardComponent.h>
#include "blackboard_keys.h"

UIsPlayerInGunRange::UIsPlayerInGunRange()
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Is Player in Gun Range");
}

void UIsPlayerInGunRange::OnBecomeRelevant(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	Super::OnBecomeRelevant(owner_comp, node_memory);

	//Gets the NPC
	ANPC_AIController* const cont = Cast<ANPC_AIController>(owner_comp.GetAIOwner());
	ANPC* const npc = Cast<ANPC>(cont->GetPawn());

	//Gets the player character 
	ACharacter* const player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	//Write true or false depending on whether the player is within the Gun range
	cont->Get_blackboard()->SetValueAsBool(bb_keys::player_is_in_gun_range,
		npc->GetDistanceTo(player) <= gun_range);
}
