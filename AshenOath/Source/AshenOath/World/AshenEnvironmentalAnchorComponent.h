// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEnvironmentalAnchorComponent.generated.h"

/**
 * UAshenEnvironmentalAnchorComponent
 * Anchors regional ley lines and cleanses localized corruption fields around Consecrated Sanctuaries.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEnvironmentalAnchorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEnvironmentalAnchorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Environment")
	float PurificationRadius = 1200.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Environment")
	bool bIsAnchorConsecrated = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Environment")
	bool ConsecrateAnchor();
};
