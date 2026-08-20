// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_BossHealthBar.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBossHealthUpdatedSignature, float, HealthPercent, int32, BossPhase);

/**
 * UAshenUserWidget_BossHealthBar
 *
 * UMG backing widget displaying boss health meters, posture break bars, and phase transition banners.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_BossHealthBar : public UUserWidget
{
	GENERATED_BODY()

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateBossHealth(float CurrentHealth, float MaxHealth, int32 CurrentPhase);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayBossName(const FText& BossName);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void ShowPhaseTransitionBanner(int32 NewPhase);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float CurrentHealthPercent = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 CurrentBossPhase = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText CurrentBossName = FText::FromString(TEXT("Unknown Entity"));

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UI|Events")
	FOnBossHealthUpdatedSignature OnBossHealthUpdated;
};
