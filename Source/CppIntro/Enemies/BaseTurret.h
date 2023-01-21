// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CppIntro/Projectile/BaseProjectile.h"
#include "GameFramework/Actor.h"
#include "BaseTurret.generated.h"

UCLASS()
class CPPINTRO_API ABaseTurret : public AActor
{
	GENERATED_BODY()
	
public:
	
	ABaseTurret();

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void Shoot();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool CanShoot();

protected:
	
	virtual void Tick(float DeltaSeconds) override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ABaseProjectile> ProjectileClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ShootingPoint;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	float ShootCooldown = 0.5;
	
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	AActor* Target;

	float LastFireTime = 0;

};



#pragma region TheFuture

/*UFUNCTION(BlueprintCallable)
void Shoot();


protected:
virtual void Tick(float DeltaSeconds) override;


UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret", meta = (AllowPrivateAccess = "true"))
float ShootCooldown = 0.5;

float LastFireTime = 0;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	

	*/

/*#2
 	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void Shoot();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool CanShoot();

	#3
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ABaseProjectile> ProjectileClass;
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Turret", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ShootingPoint;
UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	AActor* Target;
 */
#pragma endregion 