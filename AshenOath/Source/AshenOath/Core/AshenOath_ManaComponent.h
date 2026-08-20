// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_ManaComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnManaChangedSignature, float, CurrentMana, float, MaxMana);

/**
 * UAshenOath_ManaComponent
 * Manages character magical resources and spell casting requirements.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_ManaComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_ManaComponent();

protected:
	virtual void BeginPlay() override;

public:
	/** Consume mana. Returns true if successful. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Mana")
	bool ConsumeMana(float Amount);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Mana")
	float GetCurrentMana() const { return CurrentMana; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Mana")
	float GetMaxMana() const { return MaxMana; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Mana")
	void SetCurrentMana(float NewMana);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Mana")
	void SetMaxMana(float NewMaxMana);

public:
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Mana|Events")
	FOnManaChangedSignature OnManaChanged;

private:
	void UpdateManaValue(float TargetValue);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mana Settings", meta = (AllowPrivateAccess = "true"))
	float MaxMana;

	UPROPERTY(VisibleAnywhere, Category = "Mana State")
	float CurrentMana;
};
