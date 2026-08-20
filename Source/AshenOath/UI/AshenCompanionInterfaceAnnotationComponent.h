// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionInterfaceAnnotationComponent.generated.h"

/**
 * UAshenCompanionInterfaceAnnotationComponent
 * UMG/UI component handling Garrett's hand-drawn charcoal sketches and Serafina's protective Eldorian rune overlays.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionInterfaceAnnotationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionInterfaceAnnotationComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | UI")
	bool bGarrettSketchVisible = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | UI")
	bool bSerafinaRuneVisible = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | UI")
	int32 TotalAnnotationsCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void ApplyCompanionAnnotations(FName MemoryNodeID);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void AddJournalAnnotation(FName CompanionID, FName AnnotationID, const FString& TextContent);
};
