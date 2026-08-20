// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SwarmThreatHUD.generated.h"

/**
 * UAshenUserWidget_SwarmThreatHUD
 *
 * UMG backing widget rendering visual telemetry for active ghoul swarm count and squad threat level.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SwarmThreatHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateSwarmHUDDisplay(int32 SwarmCount, float FlankMultiplier);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 DisplayedSwarmCount = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedFlankMultiplier = 1.0f;
};
