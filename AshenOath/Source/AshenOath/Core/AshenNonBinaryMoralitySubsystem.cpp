// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 436: Ashen Non-Binary Morality Subsystem

#include "AshenNonBinaryMoralitySubsystem.h"

void UAshenNonBinaryMoralitySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	DispositionVector.Add(EAshenMoralDisposition::Protective, 0.0f);
	DispositionVector.Add(EAshenMoralDisposition::Detached, 0.0f);
	DispositionVector.Add(EAshenMoralDisposition::Vengeful, 0.0f);
	DispositionVector.Add(EAshenMoralDisposition::SelfSacrificing, 0.0f);
	DispositionVector.Add(EAshenMoralDisposition::Fatalistic, 0.0f);

	UE_LOG(LogTemp, Log, TEXT("UAshenNonBinaryMoralitySubsystem: Initialized — Non-Binary Morality Matrix ONLINE."));
}

void UAshenNonBinaryMoralitySubsystem::RecordDispositionAction(EAshenMoralDisposition Disposition, float Intensity)
{
	if (DispositionVector.Contains(Disposition))
	{
		DispositionVector[Disposition] += Intensity;
	}

	EAshenMoralDisposition Dominant = GetDominantDisposition();
	float Magnitude = DispositionVector[Dominant];

	OnDispositionShifted.Broadcast(Dominant, Magnitude);

	UE_LOG(LogTemp, Warning, TEXT("UAshenNonBinaryMoralitySubsystem: DISPOSITION ACTION RECORDED -> Dominant: %d (Magnitude: %.1f)."),
		(int32)Dominant, Magnitude);
}

EAshenMoralDisposition UAshenNonBinaryMoralitySubsystem::GetDominantDisposition() const
{
	EAshenMoralDisposition BestDisposition = EAshenMoralDisposition::Protective;
	float HighestValue = -1.0f;

	for (const auto& KVP : DispositionVector)
	{
		if (KVP.Value > HighestValue)
		{
			HighestValue = KVP.Value;
			BestDisposition = KVP.Key;
		}
	}

	return BestDisposition;
}
