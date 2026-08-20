// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenQualitativeStateTranslationLibrary.h"

FText UAshenQualitativeStateTranslationLibrary::GetQualitativeCorruptionDescription(float Corruption)
{
	if (Corruption >= 0.75f)
	{
		return FText::FromString(TEXT("Severely Corrupted (Shadow Saturation High)"));
	}
	else if (Corruption >= 0.35f)
	{
		return FText::FromString(TEXT("Tainted (Shadow Creep Present)"));
	}
	return FText::FromString(TEXT("Pure / Uncorrupted"));
}

FText UAshenQualitativeStateTranslationLibrary::GetQualitativeResolveDescription(float Resolve)
{
	if (Resolve >= 0.75f)
	{
		return FText::FromString(TEXT("Resolute / Steadfast"));
	}
	else if (Resolve >= 0.35f)
	{
		return FText::FromString(TEXT("Taxed / Weary"));
	}
	return FText::FromString(TEXT("Broken / Desperate"));
}
