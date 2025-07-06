// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon_H.generated.h"

UCLASS()
class XRPROJECT_API AWeapon_H : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon_H();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	ADemon_H* HugeWeapon();


	UPROPERTY(VisibleAnywhere)
	class USceneComponent* VRRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SocketAnim")
	UStaticMeshComponent* Gunweapon2;

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
	float EnemyheavyshotDamage = 100.f;

};



