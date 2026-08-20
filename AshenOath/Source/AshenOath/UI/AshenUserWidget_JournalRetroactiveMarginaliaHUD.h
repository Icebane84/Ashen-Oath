// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenCanonicalPromiseTypes.h"
#include "AshenUserWidget_JournalRetroactiveMarginaliaHUD.generated.h"

/**
 * UAshenUserWidget_JournalRetroactiveMarginaliaHUD
 * 
 * UMG/Slate widget rendering secret companion annotations on historical journal pages.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_JournalRetroactiveMarginaliaHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_JournalRetroactiveMarginaliaHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates rendered marginalia for the active page */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Journal")
	void DisplayMarginaliaEntries(const TArray<FRetroactiveMarginaliaEntry>& Entries);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Journal")
	int32 GetRenderedEntryCount() const { return ActiveRenderedCount; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	int32 ActiveRenderedCount = 0;
};
