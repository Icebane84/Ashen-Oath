// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenFieldJournalPageController.generated.h"

/**
 * UAshenFieldJournalPageController
 * Controller managing physical page flip animations, marginalia layout slots, and discovery folds.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFieldJournalPageController : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFieldJournalPageController();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Page Controller")
	int32 CurrentPageIndex = 1;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Page Controller")
	void FlipPageForward();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Page Controller")
	void FlipPageBackward();
};
