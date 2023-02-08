// Fill out your copyright notice in the Description page of Project Settings.


#include "GunFire.h"
#include "NPC_AIController.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Runtime/Engine/Classes/Engine/World.h>
#include <Engine/LatentActionManager.h>
#include "Components/SkeletalMeshComponent.h"


UGunFire::UGunFire(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Gun Fire");
}

EBTNodeResult::Type UGunFire::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	//Gets the NPC
	AAIController* const cont = owner_comp.GetAIOwner();
	ANPC* const npc = Cast<ANPC>(cont->GetPawn());

	
	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

bool UGunFire::fireing_has_finished(ANPC* const npc)
{
	return false;
}
