// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BaseProjectile.generated.h"

UCLASS()
class CPPINTRO_API ABaseProjectile : public AActor
{
	GENERATED_BODY()

public:	
	
	ABaseProjectile(const FObjectInitializer& ObjectInitializer);


	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Config|Damage",meta = (AllowPrivateAccess = "true"))
	float Damage=1.0;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, Category=Projectile, meta=(AllowPrivateAccess=true))
	USphereComponent* CollisionComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Movement, meta=(AllowPrivateAccess=true))
	UProjectileMovementComponent* ProjectileMovement = nullptr;
};
