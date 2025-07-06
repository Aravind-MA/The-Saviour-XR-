// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon_N.generated.h"

UCLASS()
class XRPROJECT_API AWeapon_N : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon_N();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	ADemon_H* Weapon();

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SocketAnim")
	UStaticMeshComponent* Gunweapon1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* StrongHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* StrongEnemyHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float MaxRange = 10000.f;

	FHitResult HitFire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	class USoundCue* StrongSpawnSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float EnemyshotDamage = 5.f;

};

