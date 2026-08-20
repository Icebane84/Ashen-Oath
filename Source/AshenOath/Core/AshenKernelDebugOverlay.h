// AshenKernelDebugOverlay.h
// Copyright Ashen Oath. All rights reserved.
// Real-time HUD visualizer overlay for testing the Psychological Runtime Kernel in Play-In-Editor (PIE).
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenSoulStateVector.h"
#include "AshenKernelDebugOverlay.generated.h"

/**
 * @class UAshenKernelDebugOverlay
 * @brief C++ UserWidget base displaying real-time state vector, imprint buffer, and debt escalation for vertical slice testing.
 */
UCLASS()
class ASHENOATH_API UAshenKernelDebugOverlay : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	/** Toggle debug overlay visibility via cheat or key binding. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Debug")
	void ToggleDebugOverlay();

protected:
	/** Formats state vector and debug metrics into readable HUD text strings. */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Debug")
	FText FormatKernelDebugText() const;

private:
	UPROPERTY(EditAnywhere, Category = "AshenOath|Debug")
	bool bShowOverlay = true;
};
