// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenUserWidget_BestiaryFinisherTacticalHUD.generated.h"

/**
 * UAshenUserWidget_BestiaryFinisherTacticalHUD
 * Displays enemy weakspot exploitation indicators (Ocular Bark, Basalt Vent, Vertical Maw, Suture Node).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_BestiaryFinisherTacticalHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FName TargetedWeakspotName = NAME_None;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EAshenPartyFinisherType ActiveBestiaryFinisher = EAshenPartyFinisherType::None;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayWeakspotPrompt(FName WeakspotName, EAshenPartyFinisherType FinisherType);
};
