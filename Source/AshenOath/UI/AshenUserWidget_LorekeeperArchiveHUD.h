// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_LorekeeperArchiveHUD.generated.h"

/**
 * UAshenUserWidget_LorekeeperArchiveHUD
 * Field journal archive UI viewing resolved psychic echoes and unsealed memory fragments.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_LorekeeperArchiveHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 UnlockedMemoryCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayLorekeeperArchive(int32 MemoryCount);
};
