// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Demon_H.generated.h"

UCLASS()
class XRPROJECT_API ADemon_H : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADemon_H();

	UFUNCTION(BlueprintCallable)
	void AttackAnim(FName Section, float PlayRate);

	UFUNCTION(BlueprintPure)
	FName SectionName();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//blueprint impletable event is used because it is a pure blueprint implementation before defining in c++
	//UFUNCTION(BlueprintImplementableEvent)
	//void HideHealthBar();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void AttackSphereBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void AttackSphereEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)override;


	//void Die();
	
	class ADemonAIController* AIcontrollerref;


private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Agro", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* SphereAttack;

	/** Behavior tree for the AI Character */
	UPROPERTY(EditAnywhere, Category = "Behavior Tree", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* Tree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Agro", meta = (AllowPrivateAccess = "true"))
	float Radius = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimMontage", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* AttackMontage;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Behavior Tree", meta = (AllowPrivateAccess = "true"))
	bool IsAttacking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveActor", meta = (AllowPrivateAccess = "true"))
	class APawn* Targetpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimMontage", meta = (AllowPrivateAccess = "true"))
	class UAnimationAsset* Death;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class USoundCue* DeathShot;

	FName RoarUp;
	FName FastL;
	FName FastR;
	FName Knock;
	FName Four;

public:
	FORCEINLINE UBehaviorTree* GetBehaviorTree() const { return Tree; }

};
