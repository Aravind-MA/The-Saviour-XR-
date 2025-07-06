// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DemonAIController.generated.h"

/**
 * 
 */
UCLASS()
class XRPROJECT_API ADemonAIController : public AAIController
{
	GENERATED_BODY()

public:
	explicit ADemonAIController(FObjectInitializer const& onjectIntiializer);

protected:
	virtual void OnPossess(APawn* InPawn) override;

private:
	UPROPERTY(BlueprintReadWrite, Category = "AI Behavior", meta = (AllowPrivateAccess = "true"))
	class UBlackboardComponent* BlackboardComponent;

	/** Behavior tree component for this enemy */
	UPROPERTY(BlueprintReadWrite, Category = "AI Behavior", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* BehaviorTreeComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess = "true"))
	float AIFieldOfView = 90.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess = "true"))
	class UAISenseConfig_Sight* SightConfig;
};
