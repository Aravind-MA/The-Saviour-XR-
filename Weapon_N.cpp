// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon_N.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Demon_H.h"

// Sets default values
AWeapon_N::AWeapon_N()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Gunweapon1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gunweapon1"));
	Gunweapon1->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AWeapon_N::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon_N::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ADemon_H* AWeapon_N::Weapon()
{

	FVector Start = Gunweapon1->GetSocketLocation(FName("Normalsocket"));
	FVector End = Start + Gunweapon1->GetForwardVector() * MaxRange;
	bool bSucesss = GetWorld()->LineTraceSingleByChannel(HitFire, Start, End, ECollisionChannel::ECC_Visibility);
	UGameplayStatics::PlaySoundAtLocation(this, StrongSpawnSound, GetActorLocation());

	if (bSucesss)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), StrongHit, HitFire.Location);
	}

	class ADemon_H* Enemyhit = Cast<ADemon_H>(HitFire.GetActor());

	if (Enemyhit)
	{
		

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), StrongEnemyHit, HitFire.Location);

		//UGameplayStatics::ApplyDamage(HitFire.GetActor(), EnemyshotDamage);

	}

	return Enemyhit;
}