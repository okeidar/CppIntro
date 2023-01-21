// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceComponent.h"


UResourceComponent::UResourceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UResourceComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentValue = MaxValue;
	SetRegeneration(bRegenerates);
}

float UResourceComponent::GetCurrentValue() const
{
	return CurrentValue;
}


void UResourceComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(RegenerationTimer);
}

float UResourceComponent::GetMaxValue() const
{
	return MaxValue;
}

void UResourceComponent::AddValue(float Value)
{
	CurrentValue += Value;
	CurrentValue = FMath::Clamp(CurrentValue, 0.f, MaxValue);
		OnValueChanged.Broadcast(CurrentValue);

}

void UResourceComponent::SubtractValue(float Value)
{
	CurrentValue -= Value;
	CurrentValue = FMath::Clamp(CurrentValue, 0.f, MaxValue);
	
	OnValueChanged.Broadcast(CurrentValue);                                                             
    if (IsDepleted())
    {
        OnDepleted.Broadcast();
    }
	
}
void UResourceComponent::Regeneration()
{
	CurrentValue = FMath::Clamp(CurrentValue + RegenerationAmount, 0.f, MaxValue);
	OnValueChanged.Broadcast(CurrentValue);
	
}
bool UResourceComponent::IsDepleted() const
{
	return CurrentValue <= 0.f;
}

void UResourceComponent::SetRegeneration(bool bRegeneration)
{
	bRegenerates=bRegeneration;
	
	if (bRegenerates)
	{
		GetWorld()->GetTimerManager().SetTimer(RegenerationTimer, this, &UResourceComponent::Regeneration, RegenerationInterval, true);
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(RegenerationTimer);
	}
}



/*
*OnValueChanged.Broadcast(CurrentValue);

	if (IsDepleted())
	{
		OnDepleted.Broadcast();
	}
 *OnValueChanged.Broadcast(CurrentValue);*/