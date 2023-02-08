// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <Perception/AIPerceptionTypes.h>
#include "NPC_AIController.generated.h"


UCLASS()
class COMPLEXAIREMAKE_API ANPC_AIController : public AAIController
{
	GENERATED_BODY()

public:
	ANPC_AIController(FObjectInitializer const& object_initalizer = FObjectInitializer::Get());
	void BeginPlay() override;
	void OnPossess(APawn* const pawn) override;
	class UBlackboardComponent* Get_blackboard() const;

private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* behavior_tree_component;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* btree;

	class UBlackboardComponent* blackboard;

	class UAISenseConfig_Sight* sight_config;
	

	UFUNCTION()
	void On_target_detected(AActor* actor, FAIStimulus const stimulus);

	void Setup_perception_system();
};
