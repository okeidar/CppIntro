// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTurret.h"

#include "Kismet/KismetMathLibrary.h"


ABaseTurret::ABaseTurret()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(Root);

	ShootingPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ShootingPoint"));
	ShootingPoint->SetupAttachment(Root);

}

void ABaseTurret::Shoot_Implementation()
{
	UE_LOG(LogTemp,Log,TEXT("I'm shooting"));
	
	LastFireTime = GetWorld()->GetTimeSeconds();
	
	FVector SpawnLocation = ShootingPoint->GetComponentLocation();	
	FRotator SpawnRotation = UKismetMathLibrary::FindLookAtRotation(SpawnLocation, Target->GetActorLocation());
	
	GetWorld()->SpawnActor<ABaseProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
}
void ABaseTurret::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if( Target && CanShoot())
	{
		Shoot();
	}
}

bool ABaseTurret::CanShoot_Implementation()
{
	return GetWorld()->GetTimeSeconds() - LastFireTime >= ShootCooldown;
}




/*
void ABaseTurret::Shoot()
{
UE_LOG(LogTemp,Log,TEXT("I'm shooting"));
}
bool ABaseTurret::CanShoot()
{
	return true;
}

void ABaseTurret::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if( CanShoot())
	{
		Shoot();
	}
}
*/



	/*#3
	 *
*	
Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
RootComponent = Root;

TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
TurretMesh->SetupAttachment(Root);

ShootingPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ShootingPoint"));
ShootingPoint->SetupAttachment(Root);
	 *ShootingPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ShootingPoint"));
	ShootingPoint->SetupAttachment(Root);

Target &&
	*/
/*void ABaseTurret::Shoot_Implementation()
{
	UE_LOG(LogTemp,Log,TEXT("I'm shooting"));
	
	LastFireTime = GetWorld()->GetTimeSeconds();
	
	FVector SpawnLocation = ShootingPoint->GetComponentLocation();	
	FRotator SpawnRotation = UKismetMathLibrary::FindLookAtRotation(SpawnLocation, Target->GetActorLocation());
	
	GetWorld()->SpawnActor<ABaseProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
}*/


/*bool ABaseTurret::CanShoot_Implementation()
{
	return GetWorld()->GetTimeSeconds() - LastFireTime >= ShootCooldown;
}*/

