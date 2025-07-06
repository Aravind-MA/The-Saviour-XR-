// Fill out your copyright notice in the Description page of Project Settings.


#include "DemonAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "Demon_H.h"



ADemonAIController::ADemonAIController(FObjectInitializer const& onjectIntiializer)
{
	PrimaryActorTick.bCanEverTick = true;

	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	check(BlackboardComponent);

	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	check(BehaviorTreeComponent);
}

void ADemonAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (InPawn == nullptr) return;

	ADemon_H* Npc = Cast<ADemon_H>(InPawn);
	if (Npc)
	{
		if (Npc->GetBehaviorTree())
		{
			BlackboardComponent->InitializeBlackboard(*(Npc->GetBehaviorTree()->BlackboardAsset));
		}
	}
}

