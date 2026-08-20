// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCharacterStanceComponent.h"
#include "AshenSoulStateVector.h"
#include "AshenPlayerStanceFXComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStanceFXTriggeredSignature, EStanceProfile, Stance, float, FXIntensity);

/**
 * UAshenPlayerStanceFXComponent
 *
 * Manages stance transition particle visual effects and sound cues
 * whenever Kaelen shifts between HunchedGuarded, BalancedSteady, and UprightGrounded stances.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPlayerStanceFXComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPlayerStanceFXComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|StanceFX")
	void TriggerStanceFX(EStanceProfile StanceProfile, float Intensity = 1.0f);

	UFUNCTION(BlueprintPure, Category = "AshenOath|StanceFX")
	EStanceProfile GetActiveStanceFX() const { return ActiveStance; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|StanceFX|Events")
	FOnStanceFXTriggeredSignature OnStanceFXTriggered;

private:
	EStanceProfile ActiveStance = EStanceProfile::Balanced_Steady;
};
