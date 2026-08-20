// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ParticleBudgetHUD.generated.h"

/**
 * UAshenUserWidget_ParticleBudgetHUD
 * Diagnostic HUD widget displaying active concurrent Niagara particle counts and enforcing performance compliance against the 2048 budget cap.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ParticleBudgetHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 ActiveParticleCount = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsBudgetExceeded = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateParticleBudget(int32 CurrentCount, int32 MaxCap);
};
