// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCartographicTypes.h"
#include "AshenLivingParchmentMapComponent.generated.h"

/**
 * UAshenLivingParchmentMapComponent
 * Component tracking player movement breadcrumbs, dynamically sketching terrain contours, and managing ink wash dissipation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingParchmentMapComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingParchmentMapComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Cartography")
	TArray<FVector> BreadcrumbPath;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Cartography")
	float MinBreadcrumbDistance = 300.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cartography")
	bool RecordPlayerPosition(FVector CurrentLocation);
};
