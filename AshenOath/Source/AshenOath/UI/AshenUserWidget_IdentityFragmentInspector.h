// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_IdentityFragmentInspector.generated.h"

/**
 * UAshenUserWidget_IdentityFragmentInspector
 * UMG backing widget rendering collected identity fragments and memory node details.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_IdentityFragmentInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 TotalCollectedFragments = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshIdentityFragmentList(int32 FragmentCount);
};
