// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ResourceComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnValueChanged, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnResourceDepleted);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPPINTRO_API UResourceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UResourceComponent();	
	
	UFUNCTION(BlueprintCallable, Category = "Resource")
	float GetCurrentValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Resource")
	float GetMaxValue() const;	

	UFUNCTION(BlueprintCallable, Category = "Resource")
	void AddValue(float Value);

	UFUNCTION(BlueprintCallable, Category = "Resource")
	void SubtractValue(float Value);

	UFUNCTION(BlueprintCallable, Category = "Resource")
	bool IsDepleted() const;

	UFUNCTION(BlueprintCallable, Category = "Resource")
	void SetRegeneration(bool bRegeneration);

	UPROPERTY(BlueprintAssignable)
	FOnValueChanged OnValueChanged;
	
	UPROPERTY(BlueprintAssignable)
	FOnResourceDepleted OnDepleted;

private:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource", meta = (AllowPrivateAccess = "true"))
	float CurrentValue;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource", meta = (AllowPrivateAccess = "true"))
	float MaxValue;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource", meta = (AllowPrivateAccess = "true"))
	float RegenerationInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource", meta = (AllowPrivateAccess = "true"))
	float RegenerationAmount;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resource", meta = (AllowPrivateAccess = "true"))
	bool bRegenerates;

	void Regeneration();
	
	FTimerHandle RegenerationTimer;
	
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};





