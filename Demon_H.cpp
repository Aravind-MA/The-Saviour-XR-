// Fill out your copyright notice in the Description page of Project Settings.


#include "Demon_H.h"
#include "Components/SphereComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h" 
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Particles/ParticleSystemComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Controller.h"
#include "Animation/AnimInstance.h"
#include "DemonAIController.h"

// Sets default values
ADemon_H::ADemon_H()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereAttack = CreateDefaultSubobject<USphereComponent>(TEXT("AttackSphere"));
	SphereAttack->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ADemon_H::BeginPlay()
{
	Super::BeginPlay();
	
	SphereAttack->OnComponentBeginOverlap.AddDynamic(this, &ADemon_H::AttackSphereBegin);
	SphereAttack->OnComponentEndOverlap.AddDynamic(this, &ADemon_H::AttackSphereEnd);

	AIcontrollerref = Cast<ADemonAIController>(GetController());

	AIcontrollerref->RunBehaviorTree(Tree);
}

// Called every frame
void ADemon_H::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//FVector Playervector = Targetpawn->GetActorLocation();

		//if (AIcontrollerref->LineOfSightTo(Targetpawn))
		//{
			//AIcontrollerref->MoveToLocation(Playervector, 100);
			//AIcontrollerref->MoveToActor(Targetpawn, 100);
			//AIcontrollerref->SetFocus(Playervector);


		//}
		//else
		//{
			//AIcontrollerref->ClearFocus(EAIFocusPriority::Gameplay);

		//}
}

// Called to bind functionality to input
void ADemon_H::AttackAnim(FName Section, float PlayRate)
{
	UAnimInstance* AnimSmellInsta = GetMesh()->GetAnimInstance();
	if (AnimSmellInsta && AttackMontage)
	{
		AnimSmellInsta->Montage_Play(AttackMontage);
		AnimSmellInsta->Montage_JumpToSection(Section, AttackMontage);
	}
}
FName ADemon_H::SectionName()
{
	FName SectionNameAnim;
	const int32 Section{ FMath::RandRange(1,5) };
	switch (Section)
	{
	case 1:
		SectionNameAnim = RoarUp;

	case 2:
		SectionNameAnim = FastL;
		break;
	case 3:
		SectionNameAnim = FastR;
		break;
	case 4:
		SectionNameAnim = Knock;
		break;

	case 5:
		SectionNameAnim = Four;
		break;


	}
	return SectionNameAnim;

}
// Called to bind functionality to input
void ADemon_H::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADemon_H::AttackSphereBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr) return;


	if (OtherActor == Targetpawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Active character123"));
		IsAttacking = true;

		if (AIcontrollerref)
		{
			AIcontrollerref->GetBlackboardComponent()->SetValueAsBool(
				TEXT("IsAttacking"),
				true
			);
		}
	}
}

void ADemon_H::AttackSphereEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == nullptr) return;


	if (OtherActor == Targetpawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Active character123"));
		IsAttacking = true;

		if (AIcontrollerref)
		{
			AIcontrollerref->GetBlackboardComponent()->SetValueAsBool(
				TEXT("IsAttacking"),
				false
			);
		}
	}
}

/*float ADemon_H::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (Health - DamageAmount <= 0)
	{
		Health = 0.0f;
		Die();
		GetMesh()->USkeletalMeshComponent::PlayAnimation(Death, false);

		UGameplayStatics::PlaySoundAtLocation(this, DeathShot, GetActorLocation());
	}
	else
	{
		Health -= DamageAmount;
	}
	return DamageAmount;

	UE_LOG(LogTemp, Warning, TEXT("Health :%f"), Health);
}

void ADemon_H::Die()
{
	HideHealthBar();
}*/
