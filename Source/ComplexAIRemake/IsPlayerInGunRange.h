// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "IsPlayerInGunRange.generated.h"

/**
 * 
 */
UCLASS()
class COMPLEXAIREMAKE_API UIsPlayerInGunRange : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UIsPlayerInGunRange();
	void OnBecomeRelevant(UBehaviorTreeComponent& owner_comp, uint8* node_memory) override;

	//Sets the range at which the gun will fire
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess = "true"))
		float gun_range = 300.0f;
};
