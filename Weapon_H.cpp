// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon_H.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
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
AWeapon_H::AWeapon_H()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Gunweapon2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gunweapon2"));
	Gunweapon2->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AWeapon_H::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon_H::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ADemon_H* AWeapon_H::HugeWeapon()
{
    FVector Start = Gunweapon2->GetSocketLocation(FName("shockSocket"));
    FVector End = Start + Gunweapon2->GetForwardVector() * MaxRange;
    bool bSuccess = GetWorld()->LineTraceSingleByChannel(HitFire, Start, End, ECollisionChannel::ECC_Visibility);

    UGameplayStatics::PlaySoundAtLocation(this, StrongSpawnSound, GetActorLocation());

    if (bSuccess)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), StrongHit, HitFire.Location);
    }

    // Cast the hit actor to ADemon_H
    ADemon_H* Enemyhit = Cast<ADemon_H>(HitFire.GetActor());

    if (Enemyhit)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), StrongEnemyHit, HitFire.Location);
    }

    // Return the enemy that was hit (or nullptr if none)
    return Enemyhit;
}
