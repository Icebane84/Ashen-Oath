// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenPrismaticRealmVeilSubsystem.h"
#include "AshenUserWidget_PrismaticVeilOverlay.generated.h"

/**
 * UAshenUserWidget_PrismaticVeilOverlay
 *
 * UMG backing widget rendering the Prismatic Void portal HUD distortion.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_PrismaticVeilOverlay : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateVeilOverlayDisplay(EAshenWorldVeilState VeilState, float DissonanceFactor);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	EAshenWorldVeilState DisplayedVeilState = EAshenWorldVeilState::MaterialWorld;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedDissonance = 1.0f;
};
