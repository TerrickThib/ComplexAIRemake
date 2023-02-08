// Fill out your copyright notice in the Description page of Project Settings.


#include "FindRandomLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "NPC_AIController.h"	
//#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "blackboard_keys.h"

UFindRandomLocation::UFindRandomLocation(FObjectInitializer const& object_initalizer)
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UFindRandomLocation::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	//Get AI controller and its NPC
	auto const cont = Cast<ANPC_AIController>(owner_comp.GetAIOwner());
	auto const npc = cont->GetPawn();

	//Obtain npc location to use as an orgin location
	FVector const orgin = npc->GetActorLocation();
	FNavLocation loc;

	//Get the navigation system and genrate a random location on the NavMesh
	UNavigationSystemV1* const nav_sys = UNavigationSystemV1::GetCurrent(GetWorld());
	if (nav_sys->GetRandomPointInNavigableRadius(orgin, search_radius, loc, nullptr))
	{
		//Writes to the blackboard
		cont->Get_blackboard()->SetValueAsVector(bb_keys::target_location, loc.Location);
	}

	//Finish with success
	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
