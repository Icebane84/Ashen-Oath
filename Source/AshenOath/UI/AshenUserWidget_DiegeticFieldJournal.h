// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenUserWidget_DiegeticFieldJournal.generated.h"

/**
 * UAshenUserWidget_DiegeticFieldJournal
 * Master UMG Widget for the physical, in-world Living Journal presenting multi-author marginalia and competing perspectives.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DiegeticFieldJournal : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FJournalEvent DisplayedJournalEvent;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RenderJournalEvent(const FJournalEvent& Event);
};
