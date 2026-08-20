// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Core/AshenOath_OathRegistryComponent.h"
#include "AshenUserWidget_OathRegistryJournal.generated.h"

/**
 * UAshenUserWidget_OathRegistryJournal
 * UMG widget rendering the live Oath Registry journal, sworn oath conditions, breach warnings, and burden levels.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_OathRegistryJournal : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	TArray<FOathRecord> DisplayedOaths;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedBurden = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshOathJournal(const TArray<FOathRecord>& Oaths, float Burden);
};
