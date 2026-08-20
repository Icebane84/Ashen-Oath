// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_PoiseComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPostureBrokenSignature);

/**
 * UAshenOath_PoiseComponent
 * Manages character stability and stagger thresholds.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_PoiseComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_PoiseComponent();

protected:
	virtual void BeginPlay() override;

public:
	/** Apply poise damage, reducing stability. Ignores damage if HyperArmor is active. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Poise")
	void ApplyPoiseDamage(float Amount);

	/** Resets current poise back to its maximum value. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Poise")
	void ResetPoise();

	UFUNCTION(BlueprintPure, Category = "AshenOath|Poise")
	float GetCurrentPoise() const { return CurrentPoise; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Poise")
	float GetMaxPoise() const { return MaxPoise; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|Poise")
	bool IsHyperArmorActive() const { return bIsHyperArmorActive; }

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Poise")
	void SetCurrentPoise(float NewPoise);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Poise")
	void SetMaxPoise(float NewMaxPoise);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Poise")
	void SetHyperArmorActive(bool bActive);

public:
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Poise|Events")
	FOnPostureBrokenSignature OnPostureBroken;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Poise Settings", meta = (AllowPrivateAccess = "true"))
	float MaxPoise;

	UPROPERTY(VisibleAnywhere, Category = "Poise State")
	float CurrentPoise;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Poise Settings", meta = (AllowPrivateAccess = "true"))
	bool bIsHyperArmorActive;
};
