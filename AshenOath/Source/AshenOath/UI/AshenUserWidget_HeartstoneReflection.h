// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenSoulStateVectorComponent.h"
#include "AshenUserWidget_HeartstoneReflection.generated.h"

/**
 * UAshenUserWidget_HeartstoneReflection
 *
 * UMG backing widget rendering the true FSoulStateVector Soul Constellation viewport during Heartstone rest (UMB-SYS-005).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_HeartstoneReflection : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayTrueSoulReflection(const FAshenSoulStateVector& TrueSoulVector);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void CloseReflectionScreen();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FAshenSoulStateVector DisplayedSoulVector;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bReflectionActive = false;
};


