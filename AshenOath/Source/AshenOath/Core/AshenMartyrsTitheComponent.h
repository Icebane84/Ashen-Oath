// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMartyrsTitheComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMartyrTitheSacrificedSignature, float, SacrificedMaxHealth, float, PartyBuffMultiplier);

/**
 * UAshenMartyrsTitheComponent
 *
 * Altruistic mechanic allowing Kaelen to permanently sacrifice max health for permanent party combat boons.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMartyrsTitheComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMartyrsTitheComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|MartyrTithe")
	bool PerformMartyrSacrifice(float SacrificedMaxHealthAmount);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MartyrTithe|Events")
	FOnMartyrTitheSacrificedSignature OnMartyrTitheSacrificed;

private:
	float TotalSacrificedHealth = 0.0f;
};
