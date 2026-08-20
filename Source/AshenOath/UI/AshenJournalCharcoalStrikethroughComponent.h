// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenJournalCharcoalStrikethroughComponent.generated.h"

/**
 * UAshenJournalCharcoalStrikethroughComponent
 * Procedural strike-through rendering over Kaelen's text when Garrett disputes his martyr complex.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenJournalCharcoalStrikethroughComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenJournalCharcoalStrikethroughComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bStrikethroughVisible = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void ApplyCharcoalStrikethrough(bool bEnableStrikethrough);
};
