// Fill out your copyright notice in the Description page of Project Settings.


#include "ChasePlayer.h"
#include "NPC_AIController.h"
#include <BehaviorTree/BlackboardComponent.h>
#include <Blueprint/AIBlueprintHelperLibrary.h>
#include "blackboard_keys.h"

UChasePlayer::UChasePlayer(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Chase Player");
}

EBTNodeResult::Type UChasePlayer::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	//Get TargetLocation from blackboard via AI controller
	ANPC_AIController* const cont = Cast<ANPC_AIController>(owner_comp.GetAIOwner());
	FVector const player_location = cont->Get_blackboard()->GetValueAsVector(bb_keys::target_location);

	//Move to the player's location	
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(cont, player_location);

	//Finish with success
	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
