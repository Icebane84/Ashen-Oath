// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemoryConstellationLensComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConstellationLensSelectedSignature, FName, ActiveLensMode, float, ConstellationZoomLevel);

/**
 * UAshenMemoryConstellationLensComponent
 *
 * Component backing the Memory Constellation Lens selection interface (UMB-UI-004 / UMB-INT-001).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryConstellationLensComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMemoryConstellationLensComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ConstellationLens")
	void SelectConstellationLens(FName LensModeTag, float Zoom = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ConstellationLens|Events")
	FOnConstellationLensSelectedSignature OnLensSelected;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ConstellationLens")
	FName ActiveLensMode = FName(TEXT("Lens.Grace"));
};
